//
// Created by illia.ilin on 8/31/2020.
//

#include "ShowAllByLabelCommand.h"
ShowAllByLabelCommand::ShowAllByLabelCommand(std::shared_ptr<TaskService> service) : service_(service) {

}
std::vector<TaskDTO> ShowAllByLabelCommand::execute() {
  return service_->showAllByLabel();
}
void ShowAllByLabelCommand::accept(std::shared_ptr<Visitor> v) {
  v->visitShowAllByLabelCommand(*this);
}
