// Copyright (c) 2012 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef SYNC_TEST_ENGINE_FAKE_MODEL_WORKER_H_
#define SYNC_TEST_ENGINE_FAKE_MODEL_WORKER_H_
#pragma once

#include <vector>

#include "base/basictypes.h"
#include "base/compiler_specific.h"
#include "base/threading/non_thread_safe.h"
#include "sync/internal_api/public/engine/model_safe_worker.h"
#include "sync/internal_api/public/util/syncer_error.h"

namespace browser_sync {

// Fake implementation of ModelSafeWorker that does work on the
// current thread regardless of the group.
class FakeModelWorker : public ModelSafeWorker {
 public:
  explicit FakeModelWorker(ModelSafeGroup group);

  // ModelSafeWorker implementation.
  virtual SyncerError DoWorkAndWaitUntilDone(
      const WorkCallback& work) OVERRIDE;
  virtual ModelSafeGroup GetModelSafeGroup() OVERRIDE;

 private:
  virtual ~FakeModelWorker();

  base::NonThreadSafe non_thread_safe_;

  const ModelSafeGroup group_;

  DISALLOW_COPY_AND_ASSIGN(FakeModelWorker);
};

}  // namespace browser_sync

#endif  // SYNC_TEST_ENGINE_FAKE_MODEL_WORKER_H_

