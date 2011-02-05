#ifndef MVC_VIEW_IVIEW_H_
#define MVC_VIEW_IVIEW_H_

#include <vector>

#include "../../mvc/model/IBasicModelObject.h"
#include "../../mvc/controller/IController.h"

using std::vector;
namespace mvc{
	namespace view{
		class IView{
		public:
			virtual void IView::render()=0;
		};
	}
}
#endif
