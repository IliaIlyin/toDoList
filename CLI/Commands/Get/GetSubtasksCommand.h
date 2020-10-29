//
// Created by illia.ilin on 8/31/2020.
//

#ifndef TODOLIST_CLI_COMMANDS_GETSUBTASKSCOMMAND_H_
#define TODOLIST_CLI_COMMANDS_GETSUBTASKSCOMMAND_H_
#include "API/TaskID.h"
#include "ClientInterface.h"
#include "Command.h"
#include "Visitor.h"
#include "API/TaskDTO.h"
#include <optional>
#include <vector>

class GetSubTaskCommand : public Command {
 public:
  GetSubTaskCommand(std::shared_ptr<ClientInterface> service, const TaskID &id);
  void execute() override;
  void accept(std::shared_ptr<Visitor> v) override;

  const std::optional<std::vector<TaskDTO>> &GetGetSubTaskCommandResult() const;
 private:
  std::shared_ptr<ClientInterface> service_;
  TaskID id_;

 private:
  std::optional<std::vector<TaskDTO>> getSubTaskCommandResult_;
};

#endif //TODOLIST_CLI_COMMANDS_GETSUBTASKSCOMMAND_H_