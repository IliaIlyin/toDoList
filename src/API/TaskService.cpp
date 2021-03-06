//
// Created by Ilya on 5/20/2020
//

#include "TaskService.h"

#include <utility>

bool TaskService::postponeTask(const TaskID &task, boost::gregorian::date date) {
  return storage_->postponeTask(task, date);
}

bool TaskService::addTask(std::string taskName,
                          boost::gregorian::date date,
                          Task::Priority priority,
                          std::string label) {
  if (taskName == "" || date.day() <= 0 || date.day() > 31 || date.month() < 1 || date.month() > 12)
    return false;
  Task t = Task::createTask(std::move(taskName), date, priority, std::move(label));
  return storage_->addTask(t);
}

bool TaskService::deleteTask(const TaskID &task) {
  return storage_->deleteTask(task);
}

bool TaskService::completeTask(const TaskID &task) {
  return storage_->completeTask(task);
}

bool TaskService::addSubTaskToParent(const TaskID &parent, std::string taskName, boost::gregorian::date date,
                                     Task::Priority priority,
                                     std::string label) {
  Task task = Task::createTask(std::move(taskName), date, priority, std::move(label));
  if (storage_->addSubTaskToParent(parent, task).has_value())
    return true;
  return false;
}

bool TaskService::addTask(Task &task) {
  return storage_->addTask(task);
}

bool TaskService::addSubTaskToParent(const TaskID &parent, Task &task) {
  if (storage_->addSubTaskToParent(parent, task).has_value())
    return true;
  return false;
}

std::vector<TaskDTO> TaskService::showAllByPriority() {
  ViewService service = storage_->getViewService();
  return dtoConvertor::convert(service.showAllByPriority());
}

std::vector<TaskDTO> TaskService::showAllByLabel() {
  auto service = storage_->getViewService();
  return dtoConvertor::convert(service.showAllByLabel());
}

std::vector<TaskDTO> TaskService::showAllByDate() {
  auto service = storage_->getViewService();
  return dtoConvertor::convert(service.showAllByDate());
}

std::vector<TaskDTO> TaskService::showTodayByPriority() {
  auto service = storage_->getViewService();
  return dtoConvertor::convert(service.showTodayByPriority());
}

std::vector<TaskDTO> TaskService::showTodayByLabel() {
  auto service = storage_->getViewService();
  return dtoConvertor::convert(service.showTodayByLabel());
}

std::vector<TaskDTO> TaskService::showDueDateByPriority(boost::gregorian::date date) {
  auto service = storage_->getViewService();
  return dtoConvertor::convert(service.showDueDateByPriority(date));
}

std::vector<TaskDTO> TaskService::showDueDateByLabel(boost::gregorian::date date) {
  auto service = storage_->getViewService();
  return dtoConvertor::convert(service.showDueDateByLabel(date));
}

std::vector<TaskDTO> TaskService::showDueDateByDate(boost::gregorian::date date) {
  auto service = storage_->getViewService();
  return dtoConvertor::convert(service.showDueDateByDate(date));
}

std::optional<std::vector<TaskDTO>> TaskService::getSubTasks(const TaskID &id) {
  auto it = storage_->getSubTasks(id);
  if (it.has_value()) {
    std::vector<std::shared_ptr<TaskEntity>> vector = it.value();
    return dtoConvertor::convert(vector);
  }
  return std::nullopt;
}

std::optional<TaskDTO> TaskService::getTask(const TaskID &id) {
  auto it = storage_->getTask(id);
  if (it.has_value()) {
    std::shared_ptr<TaskEntity> ptr = it.value();
    return dtoConvertor::convert(ptr.operator*());
  }
  return std::nullopt;
}
TaskService::TaskService(std::unique_ptr<AllDataStorageInterface> interface) : storage_(std::move(interface)) {

}
TaskService::TaskService() {
  std::unique_ptr<Storage> storage=std::make_unique<Storage>();
  std::unique_ptr<StorageService> service = std::make_unique<StorageService>(std::move(storage));
  storage_ = std::make_unique<AllDataStorage>(std::move(service));
}





