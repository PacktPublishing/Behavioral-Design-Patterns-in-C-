#pragma once
#include <vector>


#include "Checkpoint.h"

class CheckpointManager
{
	std::vector<Checkpoint> m_Checkpoints{} ;
public:
	void Save(Checkpoint checkpoint) ;
	Checkpoint Restore(size_t steps = 1) ;
	bool CheckpointAvailable()const ;

};

