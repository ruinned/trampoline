/*Instance of task t2*/

#include "embUnit.h"
#include "tpl_os.h"

DeclareTask(t1);
DeclareTask(t3);

/*test case:test the reaction of the system called with 
an activation of a task*/
static void test_t2_instance(void)
{
	int result_inst_1, result_inst_2, result_inst_3;
	
	result_inst_1 = ActivateTask(t1);
	TEST_ASSERT_EQUAL_INT(E_OK , result_inst_1); 
	
	result_inst_2 = ActivateTask(t3);
	TEST_ASSERT_EQUAL_INT(E_OK , result_inst_2);
	
	result_inst_3 = TerminateTask();
	TEST_ASSERT_EQUAL_INT(E_OK , result_inst_3);
}

/*create the test suite with all the test cases*/
TestRef TaskManagementTest_seq8_t2_instance(void)
{
	EMB_UNIT_TESTFIXTURES(fixtures) {
		new_TestFixture("test_t2_instance",test_t2_instance)
	};
	EMB_UNIT_TESTCALLER(TaskManagementTest,"TaskManagementTest_sequence8",NULL,NULL,fixtures);

	return (TestRef)&TaskManagementTest;
}