///////////////////////////////////////////////////////
//	Author: Luis Chamarro Alonso
//  Date: 11/01/2019

#pragma once

#ifndef SOULENGINE_TASK_HEADER
#define SOULENGINE_TASK_HEADER

class Task
{

	int priority;

protected:

	Task(int given_priority) : priority(given_priority)
	{
	}

public:

	int  const get_priority() const { return priority; }


	virtual void initialize() = 0;
	virtual void update() = 0;
	virtual void finalize() = 0;


	Task * get_task() { return this; }
};

/*bool operator < (const Task & a, const Task & b)
{
	return a.get_priority() < b.get_priority();
}*/


#endif