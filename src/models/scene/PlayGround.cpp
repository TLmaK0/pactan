#include "PlayGround.h"
namespace models{
	namespace scene{

		log4cxx::LoggerPtr PlayGround::logger(log4cxx::Logger::getLogger("models.scene.PlayGround"));

		PlayGround::PlayGround(){
		}

		void PlayGround::loadMap(string mapName){
			map.clear();
			this->totalPoints=0;

			ifstream mapFile(mapName.c_str());
			this->height=0;
			if (mapFile.is_open()){
				string line;
				while (! mapFile.eof() ){
					vector<MapBlockType> mapLine;

					getline (mapFile,line);
					this->width=line.length();
					for(int n=0;n<this->width;n++){
						switch (line[n]){
							case ' ':
								mapLine.push_back(PlayGround::SPACE);
								break;
							case '·':
								mapLine.push_back(PlayGround::POINT);
								totalPoints++;
								break;
							case 'X':
								mapLine.push_back(PlayGround::WALL);
								break;
							case 'C':
								this->cocosHome=*new Vector3D(n,this->height,0);
								mapLine.push_back(PlayGround::SPACE);
								break;
							case 'P':
								this->pactanHome=*new Vector3D(n,this->height,0);
								mapLine.push_back(PlayGround::SPACE);
								break;
							case 'o':
								mapLine.push_back(PlayGround::SPECIAL);
								totalPoints++;
								break;
							default:
								LOG4CXX_ERROR(logger,"Incorrect map symbol");
								exit(1);
								break;
						}
					}
					this->height++;
					map.push_back(mapLine);
				}

				mapFile.close();

				LOG4CXX_DEBUG(logger, "Map width: " << this->width);
				LOG4CXX_DEBUG(logger, "Map height: " << this->height);

				this->left=-div(this->width,2).quot;
				this->top=+div(this->height,2).quot;

				LOG4CXX_DEBUG(logger, "Map left: " << this->left);
				LOG4CXX_DEBUG(logger, "Map top: " << this->top);

			}else{
				LOG4CXX_ERROR(logger,"can't open file: "<<mapName);
				exit(-1);
			}

		}

		PlayGround::MapBlockType PlayGround::getBlockTypeAtPossition(int x, int y){
			coordToMapPossition(&x,&y);
			PlayGround::MapBlockType blockType=map[y][x];
			return blockType;
		}

		void PlayGround::eatPointAtPossition(int x, int y){
			coordToMapPossition(&x,&y);
			LOG4CXX_TRACE(logger, "Remove map poss: " << x << "," << y);
			map[y][x]=PlayGround::SPACE;
			this->totalPoints--;
			LOG4CXX_TRACE(logger, "Total points: " << this->totalPoints);
		}

		void PlayGround::coordToMapPossition(int* x, int* y){
			(*x)-=this->left;
			(*y)=this->top-(*y);
		}

		void PlayGround::mapPossitionToCoord(int* x, int* y){
			(*x)+=this->left;
			(*y)=this->top-(*y);
		}

		Vector3D PlayGround::getCocosHome(){
			int x,y;
			x=int(this->cocosHome.x);
			y=int(this->cocosHome.y);
			LOG4CXX_DEBUG(logger,"Cocos Home at: " << x << "," << y);

			mapPossitionToCoord(&x,&y);
			LOG4CXX_DEBUG(logger,"Cocos Home at: " << x << "," << y);
			return (*new Vector3D(x,y,0));
		}

		Vector3D PlayGround::getPacTanHome(){
			int x,y;
			x=int(this->pactanHome.x);
			y=int(this->pactanHome.y);

			mapPossitionToCoord(&x,&y);

			return (*new Vector3D(x,y,0));
		}
	}
}
