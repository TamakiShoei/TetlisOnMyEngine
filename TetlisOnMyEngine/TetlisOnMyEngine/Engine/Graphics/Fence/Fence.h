#ifndef	FENCE_H
#define FENCE_H

#include "../../CommonDifinition.h"

class Fence
{
public:
	Fence();
	~Fence();

	bool Initialize(ComPtr<ID3D12Device> device);
	void WaitForPreviousFrame(ComPtr<ID3D12CommandQueue> commandQueue);
	void Finalize();

	inline ID3D12Fence* Get()
	{
		return this->fence.Get();
	}

private:
	ComPtr<ID3D12Fence> fence;
	UINT fenceValue;
	HANDLE fenceEvent;		//フェンスハンドル
};

#endif