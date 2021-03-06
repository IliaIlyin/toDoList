//
// Created by illia.ilin on 8/28/2020.
//

#include "InputContext.h"
const std::string &InputContext::getName() const {
  return name_;
}
const boost::gregorian::date &InputContext::getDate() const {
  return date_;
}
Task::Priority InputContext::getPriority() const {
  return priority_;
}
const std::string &InputContext::getLabel() const {
  return label_;
}
void InputContext::setName(const std::string &name) {
  name_ = name;
}
void InputContext::setDate(const boost::gregorian::date &date) {
  date_ = date;
}
void InputContext::setPriority(Task::Priority priority) {
  priority_ = priority;
}
void InputContext::setLabel(const std::string &label) {
  label_ = label;
}
const TaskID &InputContext::getId() const {
  return id_;
}
void InputContext::setId(const TaskID &id) {
  id_ = id;
}
