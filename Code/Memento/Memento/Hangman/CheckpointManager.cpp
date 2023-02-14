#include "CheckpointManager.h"
#include <fstream>
void CheckpointManager::Save(Checkpoint checkpoint) {
	m_Checkpoints.push_back(checkpoint) ;
}

Checkpoint CheckpointManager::Restore(size_t steps) {
	if(m_Checkpoints.empty() || (steps > m_Checkpoints.size()))
		return {} ;
	auto it = m_Checkpoints.end()-steps ;
	Checkpoint checkpoint{*it} ;
	m_Checkpoints.erase(it, m_Checkpoints.end()) ;
	return checkpoint ;
}

bool CheckpointManager::CheckpointAvailable() const {
	return !m_Checkpoints.empty() ;
}

