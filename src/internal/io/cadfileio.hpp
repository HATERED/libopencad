/*******************************************************************************
 *  Project: libopencad
 *  Purpose: OpenSource CAD formats support library
 *  Author: Alexandr Borzykh, mush3d at gmail.com
 *  Language: C++
 *******************************************************************************
 *  The MIT License (MIT)
 *
 *  Copyright (c) 2017 Alexandr Borzykh
 *
 *  Permission is hereby granted, free of charge, to any person obtaining a copy
 *  of this software and associated documentation files (the "Software"), to deal
 *  in the Software without restriction, including without limitation the rights
 *  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 *  copies of the Software, and to permit persons to whom the Software is
 *  furnished to do so, subject to the following conditions:
 *
 *  The above copyright notice and this permission notice shall be included in all
 *  copies or substantial portions of the Software.
 *
 *  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 *  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 *  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 *  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 *  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 *  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 *  SOFTWARE.
 *******************************************************************************/
#ifndef LIBOPENCAD_INTERNAL_IO_CADFILEIO_HPP
#define LIBOPENCAD_INTERNAL_IO_CADFILEIO_HPP

#include <cstdint>
#include <vector>

using ByteArray = std::vector<uint8_t>;

namespace libopencad
{

    struct ICADFileIO
    {
    public:
        enum class SeekOrigin
        {
            BEG,
            CUR,
            END
        };

    public:
        virtual ~ICADFileIO();

        virtual size_t Read(size_t bytesCount) = 0;
        virtual size_t Write(const ByteArray& data) = 0;
        virtual size_t Seek(int64_t offset, SeekOrigin origin) = 0;
        virtual size_t Tell() const = 0;

        virtual bool Eof() const = 0;
        virtual bool IsOpened() const = 0;

    };

}

#endif
