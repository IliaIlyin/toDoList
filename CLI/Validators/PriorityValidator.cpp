//
// Created by illia.ilin on 8/25/2020.
//

#include "PriorityValidator.h"
CommandsValidator::ValidateResult PriorityValidator::validate(const std::string & str) {
  return CommandsValidator::validatePriority(str);
}
