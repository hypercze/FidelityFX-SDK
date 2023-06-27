// This file is part of the FidelityFX SDK.
//
// Copyright (C) 2023 Advanced Micro Devices, Inc.
// 
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files(the “Software”), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and /or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions :
// 
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
// 
// THE SOFTWARE IS PROVIDED “AS IS”, WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.

#pragma once

#include "render/dynamicbufferpool.h"
#include "core/framework.h"

namespace cauldron
{
    DynamicBufferPool::DynamicBufferPool()
    {
        const CauldronConfig* pConfig = GetConfig();
        m_TotalSize = AlignUp<uint32_t>(static_cast<uint32_t>(pConfig->DynamicBufferPoolSize), 256u);

        // Create the backing ring buffer
        m_RingBuffer.Create(pConfig->BackBufferCount, m_TotalSize);
    }

    DynamicBufferPool::~DynamicBufferPool()
    {
        // Destroy the backing ring buffer
        m_RingBuffer.Destroy();

        delete m_pResource;
    }

    void DynamicBufferPool::BeginFrame()
    {
        m_RingBuffer.BeginFrame();
    }

} // namespace cauldron
