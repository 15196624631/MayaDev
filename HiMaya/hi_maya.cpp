#include <maya/MGlobal.h>
#include <maya/MSimple.h>

DeclareSimpleCommand(HiMaya, "184327932@qq.com", "2018.08.06.01");

MStatus HiMaya::doIt(const MArgList& args)
{
	MGlobal::displayInfo("Hi, Maya. ���Ĳ��ԣ���ð���");
	return MS::kSuccess;
}