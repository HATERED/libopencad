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
#ifndef LIBOPENCAD_INTERNAL_IO_DEFAULTCADFILEIO_HPP
#define LIBOPENCAD_INTERNAL_IO_DEFAULTCADFILEIO_HPP

#include "cadfileio.hpp"

#include <fstream>

namespace libopencad
{

    class DefaultCADFileIO : public ICADFileIO
    {
    public:
        DefaultCADFileIO(const std::string& path);

        virtual ByteArray Read(size_t bytesCount);
        virtual size_t Write(const ByteArray& data);
        virtual size_t Seek(int64_t offset, SeekOrigin origin);

        virtual size_t Tell() const
        { return _fileStream.tellg(); }

        virtual bool Eof() const
        { return _fileStream.eof(); }

        virtual bool IsOpened() const
        { return _fileStream.is_open(); }
    private:
        std::fstream        _fileStream;
    };
}

#endif
