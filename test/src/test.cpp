#include "cute.h"
#include "ide_listener.h"
#include "cute_runner.h"
#include "../../src/game/scene/Scene.cpp"
#include "../../src/game/agents/PacTan.cpp"

void BuildSceneTest() {
	ASSERT(Scene::build());
}

void PacTanTest(){

}

void runSuite(){

	cute::suite s;
	//TODO add your test here
	s.push_back(CUTE(BuildSceneTest));
	s.push_back(CUTE(PacTanTest));
	cute::ide_listener lis;
	cute::makeRunner(lis)(s, "The Suite");
}

int main(int argc, char *argv[]){

	runSuite();
    return 0;
}
