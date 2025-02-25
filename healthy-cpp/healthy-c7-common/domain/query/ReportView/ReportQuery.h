#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: DY
 @Date: 2024/01/19 11:36:29

 Licensed under the Apache License, Version 2.0 (the "License");
 you may not use this file except in compliance with the License.
 You may obtain a copy of the License at

	  https://www.apache.org/licenses/LICENSE-2.0

 Unless required by applicable law or agreed to in writing, software
 distributed under the License is distributed on an "AS IS" BASIS,
 WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 See the License for the specific language governing permissions and
 limitations under the License.
*/
#ifndef _REPORT_QUERY_
#define _REPORT_QUERY_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 报告打印报告预览
 * 
 */
class ReportQuery : public PageQuery
{
	DTO_INIT(ReportQuery, PageQuery);

	// 体检人员编号
	API_DTO_FIELD_DEFAULT(String, personId, ZH_WORDS_GETTER("report.field.personId"));
};



#include OATPP_CODEGEN_END(DTO)
#endif // !_REPORT_QUERY_