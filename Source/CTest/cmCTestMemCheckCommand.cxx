/* Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
   file Copyright.txt or https://cmake.org/licensing for details.  */
#include "cmCTestMemCheckCommand.h"

#include "cmCTest.h"
#include "cmCTestGenericHandler.h"

cmCTestGenericHandler* cmCTestMemCheckCommand::InitializeActualHandler()
{
  cmCTestGenericHandler* handler =
    this->CTest->GetInitializedHandler("memcheck");

  this->CTest->SetCTestConfigurationFromCMakeVariable(
    this->Makefile, "MemoryCheckType", "CTEST_MEMORYCHECK_TYPE", this->Quiet);
  this->CTest->SetCTestConfigurationFromCMakeVariable(
    this->Makefile, "MemoryCheckSanitizerOptions",
    "CTEST_MEMORYCHECK_SANITIZER_OPTIONS", this->Quiet);
  this->CTest->SetCTestConfigurationFromCMakeVariable(
    this->Makefile, "MemoryCheckCommand", "CTEST_MEMORYCHECK_COMMAND",
    this->Quiet);
  this->CTest->SetCTestConfigurationFromCMakeVariable(
    this->Makefile, "MemoryCheckCommandOptions",
    "CTEST_MEMORYCHECK_COMMAND_OPTIONS", this->Quiet);
  this->CTest->SetCTestConfigurationFromCMakeVariable(
    this->Makefile, "MemoryCheckSuppressionFile",
    "CTEST_MEMORYCHECK_SUPPRESSIONS_FILE", this->Quiet);

  handler->SetQuiet(this->Quiet);
  return handler;
}
