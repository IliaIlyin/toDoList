//
// Created by Ilya on 7/30/2020.
//

#ifndef TODOLIST_VIEWS_LABELVIEW_H_
#define TODOLIST_VIEWS_LABELVIEW_H_
#include"../Display/Display.h"
#include"../Model/HashTaskID.h"
#include"../Model/TaskEntity.h"
#include"../Model/IdGenerator.h"
#include"GeneralView.h"
#include<map>
#include<vector>
#include<memory>
#include <ctime>
class LabelView:public GeneralView<LabelView> {
 public:
  std::vector<std::weak_ptr<TaskEntity> > showAll() override ;
  std::vector<std::weak_ptr<TaskEntity> > showToday() override ;
  std::vector<std::weak_ptr<TaskEntity> > showDueDate(time_t date) override ;
 private:
  std::multimap<std::string,std::weak_ptr<TaskEntity> > labels;
};

#endif //TODOLIST_VIEWS_LABELVIEW_H_
