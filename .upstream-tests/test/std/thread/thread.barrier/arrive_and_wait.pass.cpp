//===----------------------------------------------------------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//
//
// UNSUPPORTED: libcpp-has-no-threads
// UNSUPPORTED: pre-sm-60

// <cuda/std/barrier>

#include <cuda/std/barrier>
#include <cuda/std/thread>

#include "test_macros.h"

int main(int, char**)
{
  cuda::std::barrier b(2);

  cuda::std::thread t([&](){
    for(int i = 0; i < 10; ++i)
      b.arrive_and_wait();
  });
  for(int i = 0; i < 10; ++i)
    b.arrive_and_wait();
  t.join();

  return 0;
}