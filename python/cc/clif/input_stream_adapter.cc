// Copyright 2019 Google Inc.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//
///////////////////////////////////////////////////////////////////////////////

#include "tink/python/cc/input_stream_adapter.h"

#include "third_party/pybind11/include/pybind11/pybind11.h"
#include "tink/python/cc/clif/status_casters.h"

namespace crypto {
namespace tink {

PYBIND11_MODULE(input_stream_adapter, m) {
  namespace py = pybind11;

  // TODO(b/146492561): Reduce the number of complicated lambdas.
  py::class_<InputStreamAdapter>(m, "InputStreamAdapter")
      .def(
          "read1",
          [](InputStreamAdapter *self, int64_t size)
              -> util::StatusOr<py::bytes> { return self->Read1(size); },
          py::arg("size"))
      .def(
          "read",
          [](InputStreamAdapter *self, int64_t size)
              -> util::StatusOr<py::bytes> { return self->Read(size); },
          py::arg("size"));
}

}  // namespace tink
}  // namespace crypto
