#include "stdafx.h"
#include "criticalModifyController.h"
#include "../../service/critical/CriticalListService.h"
#include "../ApiDeclarativeServicesHelper.h"

Uint64JsonVO::Wrapper CriticalModifyController::execModifyCritical(const CriticalListDTO::Wrapper& dto)
{
	// 定义返回数据对象
	auto jvo = Uint64JsonVO::createShared();
	//// 参数校验
	//if (!dto->id)
	//{
	//	jvo->init(UInt64(-1), RS_PARAMS_INVALID);
	//	return jvo;
	//}
	// 定义一个Service
	CriticalListService service;
	// 执行数据修改
	int id = service.updateData(dto);
	if (id > 0) {
		jvo->success(id);
	}
	else
	{
		jvo->fail(id);
	}
	// 响应结果
	return jvo;
}
