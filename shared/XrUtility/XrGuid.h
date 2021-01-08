//*********************************************************
//    Copyright (c) Microsoft. All rights reserved.
//
//    Apache 2.0 License
//
//    You may obtain a copy of the License at
//    http://www.apache.org/licenses/LICENSE-2.0
//
//    Unless required by applicable law or agreed to in writing, software
//    distributed under the License is distributed on an "AS IS" BASIS,
//    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or
//    implied. See the License for the specific language governing
//    permissions and limitations under the License.
//
//*********************************************************
#pragma once

#include <memory.h>
#include <functional>
#include <string.h>

namespace xr {
    template <typename GUID1, typename GUID2>
    void CopyGuid(GUID1& dest, const GUID2& src) noexcept {
        static_assert(sizeof(GUID1) == sizeof(GUID2), "GUID sizes must be equal");
#ifdef _MSC_VER
        memcpy_s(&dest, sizeof(GUID1), &src, sizeof(GUID2));
#else
        memcpy(&dest, &src, sizeof(GUID2));
#endif
    }
} // namespace xr
