/*
 * Copyright (c) 2015 2016, Intel Corporation
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 *   * Redistributions of source code must retain the above copyright notice,
 *     this list of conditions and the following disclaimer.
 *   * Redistributions in binary form must reproduce the above copyright
 *     notice, this list of conditions and the following disclaimer in the
 *     documentation and/or other materials provided with the distribution.
 *   * Neither the name of Intel Corporation nor the names of its contributors
 *     may be used to endorse or promote products derived from this software
 *     without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
 * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

/*
 * Result representing an error.
 */

#ifndef _CLI_FRAMEWORK_ERRORRESULT_H_
#define _CLI_FRAMEWORK_ERRORRESULT_H_

#include "SimpleResult.h"

namespace cli
{
namespace framework
{

/*!
 * ErrorResult XML Tag
 */
const std::string errorResultXmlTag = "Error";

/*!
 * ErrorResult JSON description string
 */
const std::string errorResultJsonDescription = "Error_Description";

/*!
 * ErrorResult XML Type Attribute Name
 */
const std::string errorResultXmlTypeAttribute = "Type";

/*!
 * Result representing an error.
 */
class ErrorResult : public SimpleResult
{
public:

	/*!
	 * Initialize a new error result object
	 * @param prefix
	 * 		An optional string prefix describing the operation that failed
	 *
	 */
	ErrorResult(std::string prefix = "");

	/*!
	 * Initialize a new error result object
	 * @param errorCode
	 * 		An error code
	 * @param errorMessage
	 * 		A string error message
	 * 	@param prefix
	 * 		An optional string prefix describing the operation that failed
	 */
	ErrorResult(int errorCode, std::string errorMessage = "", std::string prefix = "");

	/*!
	 *
	 * @return
	 * 		returns the error result as a string
	 */
	virtual std::string outputText() const;
	/*!
	 *
	 * @return
	 * 		returns the error result as xml
	 */
	virtual std::string outputXml() const;
	/*!
	 *
	 * @return
	 * 	returns the error result such that esx can understand it
	 */
	virtual std::string outputEsxXml() const;
	/*!
	 *
	 * @return
	 * 		returns the error result as json
	 */
	virtual std::string outputJson() const;


private:
	std::string m_prefix;
	std::string getErrorString() const;

};
}
}

#endif /* ERRORRESULT_H_ */
