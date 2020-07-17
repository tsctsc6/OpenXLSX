/*

   ____                               ____      ___ ____       ____  ____      ___
  6MMMMb                              `MM(      )M' `MM'      6MMMMb\`MM(      )M'
 8P    Y8                              `MM.     d'   MM      6M'    ` `MM.     d'
6M      Mb __ ____     ____  ___  __    `MM.   d'    MM      MM        `MM.   d'
MM      MM `M6MMMMb   6MMMMb `MM 6MMb    `MM. d'     MM      YM.        `MM. d'
MM      MM  MM'  `Mb 6M'  `Mb MMM9 `Mb    `MMd       MM       YMMMMb     `MMd
MM      MM  MM    MM MM    MM MM'   MM     dMM.      MM           `Mb     dMM.
MM      MM  MM    MM MMMMMMMM MM    MM    d'`MM.     MM            MM    d'`MM.
YM      M9  MM    MM MM       MM    MM   d'  `MM.    MM            MM   d'  `MM.
 8b    d8   MM.  ,M9 YM    d9 MM    MM  d'    `MM.   MM    / L    ,M9  d'    `MM.
  YMMMM9    MMYMMM9   YMMMM9 _MM_  _MM_M(_    _)MM_ _MMMMMMM MYMMMM9 _M(_    _)MM_
            MM
            MM
           _MM_

  Copyright (c) 2018, Kenneth Troldal Balslev

  All rights reserved.

  Redistribution and use in source and binary forms, with or without
  modification, are permitted provided that the following conditions are met:
  - Redistributions of source code must retain the above copyright
    notice, this list of conditions and the following disclaimer.
  - Redistributions in binary form must reproduce the above copyright
    notice, this list of conditions and the following disclaimer in the
    documentation and/or other materials provided with the distribution.
  - Neither the name of the author nor the
    names of any contributors may be used to endorse or promote products
    derived from this software without specific prior written permission.

  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
  ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
  WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
  DISCLAIMED. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY
  DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
  (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
  LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
  ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
  (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
  SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

 */

#ifndef OPENXLSX_IMPL_XLCONTENTTYPES_H
#define OPENXLSX_IMPL_XLCONTENTTYPES_H

// ===== Standard Library Includes ===== //
#include <map>
#include <string>
#include <vector>

// ===== OpenXLSX Includes ===== //
#include "XLAbstractXMLFile.hpp"
#include "XLEnums.hpp"
#include "XLXmlParser.hpp"

namespace OpenXLSX
{
    // ================================================================================
    // XLContentItem Class
    // ================================================================================

    /**
     * @brief
     */
    class XLContentItem
    {
        friend class XLContentTypes;

    public:    // ---------- Public Member Functions ---------- //
        /**
         * @brief
         * @param node
         * @param path
         * @param type
         * @return
         */
        explicit XLContentItem(XMLNode node = XMLNode());

        /**
         * @brief
         */
        ~XLContentItem() = default;

        /**
         * @brief
         * @param other
         * @return
         */
        XLContentItem(const XLContentItem& other) = default;

        /**
         * @brief
         * @param other
         * @return
         */
        XLContentItem(XLContentItem&& other) noexcept = default;

        /**
         * @brief
         * @param other
         * @return
         */
        XLContentItem& operator=(const XLContentItem& other) = default;

        /**
         * @brief
         * @param other
         * @return
         */
        XLContentItem& operator=(XLContentItem&& other) noexcept = default;

        /**
         * @brief
         * @return
         */
        XLContentType Type() const;

        /**
         * @brief
         * @return
         */
        std::string Path() const;

    private:                   // ---------- Private Member Variables ---------- //
        XMLNode m_contentNode; /**< */
    };

    // ================================================================================
    // XLContentTypes Class
    // ================================================================================

    /**
     * @brief The purpose of this class is to load, store add and save item in the [Content_Types].xml file.
     */
    class XLContentTypes : public XLAbstractXMLFile
    {
    public:    // ---------- Public Member Functions ---------- //
        XLContentTypes() = default;
        /**
         *
         * @param parent
         * @param xmlData
         */
        explicit XLContentTypes(XLXmlData* xmlData);

        /**
         * @brief Destructor
         */
        ~XLContentTypes() override = default;

        /**
         * @brief
         * @param other
         */
        XLContentTypes(const XLContentTypes& other) = default;

        /**
         * @brief
         * @param other
         */
        XLContentTypes(XLContentTypes&& other) noexcept = default;

        /**
         * @brief
         * @param other
         * @return
         */
        XLContentTypes& operator=(const XLContentTypes& other) = default;

        /**
         * @brief
         * @param other
         * @return
         */
        XLContentTypes& operator=(XLContentTypes&& other) noexcept = default;

        /**
         * @brief Add a new override key/value pair to the data store.
         * @param path The key
         * @param type The value
         */
        void AddOverride(const std::string& path, XLContentType type);

        /**
         * @brief
         * @param path
         */
        void DeleteOverride(const std::string& path);

        /**
         * @brief
         * @param item
         */
        void DeleteOverride(XLContentItem& item);

        /**
         * @brief
         * @param path
         * @return
         */
        XLContentItem ContentItem(const std::string& path);

        std::vector<XLContentItem> getContentItems();

    protected:    // ---------- Protected Member Functions ---------- //
        /**
         * @brief
         * @return
         */
        bool ParseXMLData() override;
    };
}    // namespace OpenXLSX

#endif    // OPENXLSX_IMPL_XLCONTENTTYPES_H
