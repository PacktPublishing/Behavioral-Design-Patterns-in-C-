#pragma once
class DataModel;

class Format
{
public:
	virtual void Export(DataModel *pModel) = 0 ;
	virtual ~Format() = default ;
};

