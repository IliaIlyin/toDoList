//
// Created by Ilya on 9/15/2020.
//

#ifndef TODOLIST_CLI_BUILDERS_SHOW_SHOWDUEDATE_SHOWDUEDATEBYPRIORITYCOMMANDBUILDER_H_
#define TODOLIST_CLI_BUILDERS_SHOW_SHOWDUEDATE_SHOWDUEDATEBYPRIORITYCOMMANDBUILDER_H_

#include "Builder.h"
#include "InputStateMachine.h"
#include "Validators/InputValidators/DateValidator.h"
#include "States/InputDataStates/TaskDateState.h"
#include "Commands/CancelCommand.h"
#include "Commands/Show/ShowDueDate/ShowDueDateByPriorityCommand.h"

class ShowDueDateByPriorityCommandBuilder : public Builder {
 public:
  std::shared_ptr<Command> buildCommand(std::shared_ptr<CoreAPIInterface> service) override;
 public:
  ShowDueDateByPriorityCommandBuilder(std::unique_ptr<InputStateMachineInterface> machine);
 private:
  std::unique_ptr<InputStateMachineInterface> machine_;
};

#endif //TODOLIST_CLI_BUILDERS_SHOW_SHOWDUEDATE_SHOWDUEDATEBYPRIORITYCOMMANDBUILDER_H_
