//
// Created by Ilya on 7/26/2020.
//

#include <gtest/gtest.h>

#include "API/Task.h"

using testing::Eq;

class TaskTest : public ::testing::Test {

};

bool operator != (const Task& task1, const Task& task2){
return !(task1==task2);
}

 TEST_F(TaskTest,shouldCreateTask){
    Task task = Task::createTask("Lol",boost::gregorian::date{2000,12,9},Task::Priority::FIRST,"label");
    ASSERT_EQ(task.getPriority(),Task::Priority::FIRST);
    ASSERT_EQ(task.getDate(),(boost::gregorian::date{2000,12,9}));
    ASSERT_TRUE(task.getName()=="Lol");
    ASSERT_TRUE(task.getLabel()=="label");
}
TEST_F(TaskTest,shouldGetTaskName){
  Task task = Task::createTask("Lol",boost::gregorian::date{2000,12,9},Task::Priority::FIRST,"label");
  ASSERT_EQ("Lol",task.getName());
}
TEST_F(TaskTest,shouldGetTaskDate){
  Task task = Task::createTask("Lol",boost::gregorian::date{2000,12,9},Task::Priority::FIRST,"label");
  ASSERT_EQ((boost::gregorian::date{2000,12,9}),task.getDate());
}
TEST_F(TaskTest,shouldGetTaskPriority){
  Task task = Task::createTask("Lol",boost::gregorian::date{2000,12,9},Task::Priority::FIRST,"label");
  ASSERT_EQ(Task::Priority::FIRST,task.getPriority());
}
TEST_F(TaskTest,shouldGetTaskLabel){
Task task = Task::createTask("Lol",boost::gregorian::date{2000,12,9},Task::Priority::FIRST,"label");
ASSERT_EQ("label",task.getLabel());
}
TEST_F(TaskTest,shouldCompareTasks){

  Task task = Task::createTask("Lol",boost::gregorian::date{2000,12,9},Task::Priority::FIRST,"label");
  Task task2 = Task::createTask("Lol",boost::gregorian::date{2000,12,9},Task::Priority::FIRST,"label");
  ASSERT_EQ(task,task2);
  Task task3= Task::createTask("Loli",boost::gregorian::date{2000,12,9},Task::Priority::FIRST,"label");
  ASSERT_NE(task,task3);
  Task task4 = Task::createTask("Lol",boost::gregorian::date{2000,12,9},Task::Priority::SECOND,"label");
  ASSERT_NE(task,task4);
  Task task6 = Task::createTask("Lol",boost::gregorian::date{2000,12,9},Task::Priority::SECOND,"fsdfsd");
  ASSERT_NE(task,task6);
  Task task5 = Task::createTask("Lol",boost::gregorian::date{1800,12,9},Task::Priority::SECOND,"label");
  ASSERT_NE(task,task5);
}