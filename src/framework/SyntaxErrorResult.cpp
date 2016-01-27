/*
 * Copyright (c) 2015, Intel Corporation
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

#include "SyntaxErrorResult.h"
#include "cr_i18n.h"

cli::framework::CommandSpecList cli::framework::SyntaxErrorResult::getPotentialCommands()
{
	Trace trace(__FILE__, __FUNCTION__, __LINE__);
	return m_potentialCommands;
}

void cli::framework::SyntaxErrorResult::setPotentialCommands(CommandSpecList commands)
{
	Trace trace(__FILE__, __FUNCTION__, __LINE__);
	m_potentialCommands = commands;
}

cli::framework::SyntaxErrorResult::SyntaxErrorResult() :
		ErrorResult(ERRORCODE_SYNTAX)
{
	Trace trace(__FILE__, __FUNCTION__, __LINE__);
}

cli::framework::SyntaxErrorResult::SyntaxErrorResult(std::string errorMessage) :
		ErrorResult(ERRORCODE_SYNTAX)
{
	m_result = errorMessage;
}

std::string cli::framework::SyntaxErrorResult::outputText() const
{
	Trace(__FILE__, __FUNCTION__, __LINE__);
	std::string result = ErrorResult::outputText();

	if (m_potentialCommands.size() > 0)
	{

		result += TR("\nDid you mean: \n");
		for (size_t i = 0; i < m_potentialCommands.size(); i++)
		{
			result += m_potentialCommands[i].asStr() + "\n";
		}
	}

	return result;
}

/*
 * Don't add potential commands to the XML output.  Most likely is being run in an automated fashion
 * and won't be helpful.
 */
std::string cli::framework::SyntaxErrorResult::outputXml() const
{
	Trace(__FILE__, __FUNCTION__, __LINE__);
	return ErrorResult::outputXml();
}

std::string cli::framework::SyntaxErrorResult::outputJson() const
{
	Trace(__FILE__, __FUNCTION__, __LINE__);
	return ErrorResult::outputJson();
}

std::string cli::framework::SyntaxErrorResult::outputEsxXml() const
{
	Trace(__FILE__, __FUNCTION__, __LINE__);
	return ErrorResult::outputEsxXml();
}