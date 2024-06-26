﻿# CMakeList.txt: CodingTest에 대한 CMake 프로젝트, 여기에 소스를 포함하고
# 프로젝트 특정 논리를 정의합니다.
#
cmake_minimum_required (VERSION 3.8)

# 지원되는 경우 MSVC 컴파일러에 대해 핫 다시 로드 사용하도록 설정합니다.
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

project ("CodingTest")

# 이 프로젝트의 실행 파일에 소스를 추가합니다.
add_executable (CodingTest 
	"main.cpp"
	"algorithm/CodingTest.cpp"
	"algorithm/CodingTest.h"
	"algorithm/recursive/2_TowerOfHanoi.cpp"
	"algorithm/recursive/2_TowerOfHanoi.h"
 "algorithm/bfs/2_RicochetRobot.cpp" "algorithm/bfs/2_RicochetRobot.h" "algorithm/sort/2_InterceptionSystem.cpp" "algorithm/sort/2_InterceptionSystem.h" "main.h" "algorithm/others/2_TwoCircle.cpp" "algorithm/others/2_TwoCircle.h" "algorithm/others/2_ContinualSequenceNum.cpp" "algorithm/others/2_ContinualSequenceNum.h" "algorithm/stack/2_TackProcess.cpp" "algorithm/stack/2_TaskProcess.h" "algorithm/others/2_BilliardsPractice.h" "algorithm/others/2_BilliardsPractice.cpp" "algorithm/bfs/2_MazeEscape.cpp" "algorithm/bfs/2_MazeEscape.h" "algorithm/bfs/2_DesertIsland.h" "algorithm/bfs/2_DesertIsland.cpp" "algorithm/goorm/Infection.cpp" "algorithm/goorm/Infection.h" "algorithm/others/2_HotelRental.h" "algorithm/others/2_HotelRental.cpp" "algorithm/bfs/2_ConvertNum.cpp" "algorithm/bfs/2_ConvertNum.h")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET CodingTest PROPERTY CXX_STANDARD 20)
endif()

# TODO: 필요한 경우 테스트를 추가하고 대상을 설치합니다.
