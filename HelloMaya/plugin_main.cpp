#include "first_class.h"
#include <maya/MGlobal.h>
#include <maya/MPxCommand.h>
#include <maya/MFnPlugin.h>
#include <maya/MString.h>
#include <maya/MArgList.h>
#include <maya/MObject.h>

#define __VENDOR "kingmax_res@163.com | 184327932@qq.com | iJasonLee@WeChat"
#define __VERSION "2018.08.06.01"

namespace WendyAndAndy
{
	class SecondClass : public MPxCommand
	{
	public:
		SecondClass() = default;
		~SecondClass() = default;

		MStatus doIt(const MArgList &args)
		{
			MGlobal::displayInfo("SecondClass say hello");
			return MS::kSuccess;
		}

		static void* creator()
		{
			return new SecondClass();
		}
	};
}

//���ز��ʱע������ڵ��
MStatus initializePlugin(MObject obj)
{
	MFnPlugin plugin(obj, __VENDOR, __VERSION);
	MStatus status;
	status = plugin.registerCommand("myCmd1", WendyAndAndy::FirstClass::creator); //��������ֿ�����㶨��
	if (!status)
		status.perror("register command myCmd1 failed");

	//ע��ڶ�������
	status = plugin.registerCommand("hello", WendyAndAndy::SecondClass::creator); //��������ֿ�����㶨��
	if (!status)
		status.perror("register command hello failed");

	return MS::kSuccess;
}

//ж�ز��ʱȡ��ע��
MStatus uninitializePlugin(MObject obj)
{
	MFnPlugin plugin(obj, __VENDOR, __VERSION);
	MStatus status;
	//ȡ��ע��
	status = plugin.deregisterCommand("myCmd1"); //�����������ǰ�涨���һ��
	if (!status)
		status.perror("deregister command myCmd1 failed");

	//ע��ڶ�������
	status = plugin.deregisterCommand("hello"); //�����������ǰ�涨���һ��
	if (!status)
		status.perror("deregister command hello failed");

	return MS::kSuccess;
}