// Copyright 1998-2015 Epic Games, Inc. All Rights Reserved.

#include "CorePrivatePCH.h"
#include "GenericApplication.h"
#include "GenericApplicationMessageHandler.h"

const FGamepadKeyNames::Type FGamepadKeyNames::Invalid(NAME_None);

// Ensure that the GamepadKeyNames match those in InputCoreTypes.cpp
const FGamepadKeyNames::Type FGamepadKeyNames::LeftAnalogX("Gamepad_LeftX");
const FGamepadKeyNames::Type FGamepadKeyNames::LeftAnalogY("Gamepad_LeftY");
const FGamepadKeyNames::Type FGamepadKeyNames::RightAnalogX("Gamepad_RightX");
const FGamepadKeyNames::Type FGamepadKeyNames::RightAnalogY("Gamepad_RightY");
const FGamepadKeyNames::Type FGamepadKeyNames::LeftTriggerAnalog("Gamepad_LeftTriggerAxis");
const FGamepadKeyNames::Type FGamepadKeyNames::RightTriggerAnalog("Gamepad_RightTriggerAxis");

const FGamepadKeyNames::Type FGamepadKeyNames::LeftThumb("Gamepad_LeftThumbstick");
const FGamepadKeyNames::Type FGamepadKeyNames::RightThumb("Gamepad_RightThumbstick");
const FGamepadKeyNames::Type FGamepadKeyNames::SpecialLeft("Gamepad_Special_Left");
const FGamepadKeyNames::Type FGamepadKeyNames::SpecialRight("Gamepad_Special_Right");
const FGamepadKeyNames::Type FGamepadKeyNames::FaceButtonBottom("Gamepad_FaceButton_Bottom");
const FGamepadKeyNames::Type FGamepadKeyNames::FaceButtonRight("Gamepad_FaceButton_Right");
const FGamepadKeyNames::Type FGamepadKeyNames::FaceButtonLeft("Gamepad_FaceButton_Left");
const FGamepadKeyNames::Type FGamepadKeyNames::FaceButtonTop("Gamepad_FaceButton_Top");
const FGamepadKeyNames::Type FGamepadKeyNames::LeftShoulder("Gamepad_LeftShoulder");
const FGamepadKeyNames::Type FGamepadKeyNames::RightShoulder("Gamepad_RightShoulder");
const FGamepadKeyNames::Type FGamepadKeyNames::LeftTriggerThreshold("Gamepad_LeftTrigger");
const FGamepadKeyNames::Type FGamepadKeyNames::RightTriggerThreshold("Gamepad_RightTrigger");
const FGamepadKeyNames::Type FGamepadKeyNames::DPadUp("Gamepad_DPad_Up");
const FGamepadKeyNames::Type FGamepadKeyNames::DPadDown("Gamepad_DPad_Down");
const FGamepadKeyNames::Type FGamepadKeyNames::DPadRight("Gamepad_DPad_Right");
const FGamepadKeyNames::Type FGamepadKeyNames::DPadLeft("Gamepad_DPad_Left");

const FGamepadKeyNames::Type FGamepadKeyNames::LeftStickUp("Gamepad_LeftStick_Up");
const FGamepadKeyNames::Type FGamepadKeyNames::LeftStickDown("Gamepad_LeftStick_Down");
const FGamepadKeyNames::Type FGamepadKeyNames::LeftStickRight("Gamepad_LeftStick_Right");
const FGamepadKeyNames::Type FGamepadKeyNames::LeftStickLeft("Gamepad_LeftStick_Left");

const FGamepadKeyNames::Type FGamepadKeyNames::RightStickUp("Gamepad_RightStick_Up");
const FGamepadKeyNames::Type FGamepadKeyNames::RightStickDown("Gamepad_RightStick_Down");
const FGamepadKeyNames::Type FGamepadKeyNames::RightStickRight("Gamepad_RightStick_Right");
const FGamepadKeyNames::Type FGamepadKeyNames::RightStickLeft("Gamepad_RightStick_Left");

const FGamepadKeyNames::Type FGamepadKeyNames::MotionController_Left_FaceButton1("MotionController_Left_FaceButton1");
const FGamepadKeyNames::Type FGamepadKeyNames::MotionController_Left_FaceButton2("MotionController_Left_FaceButton2");
const FGamepadKeyNames::Type FGamepadKeyNames::MotionController_Left_FaceButton3("MotionController_Left_FaceButton3");
const FGamepadKeyNames::Type FGamepadKeyNames::MotionController_Left_FaceButton4("MotionController_Left_FaceButton4");
const FGamepadKeyNames::Type FGamepadKeyNames::MotionController_Left_FaceButton5("MotionController_Left_FaceButton5");
const FGamepadKeyNames::Type FGamepadKeyNames::MotionController_Left_FaceButton6("MotionController_Left_FaceButton6");
const FGamepadKeyNames::Type FGamepadKeyNames::MotionController_Left_FaceButton7("MotionController_Left_FaceButton7");
const FGamepadKeyNames::Type FGamepadKeyNames::MotionController_Left_FaceButton8("MotionController_Left_FaceButton8");

const FGamepadKeyNames::Type FGamepadKeyNames::MotionController_Left_Shoulder("MotionController_Left_Shoulder");
const FGamepadKeyNames::Type FGamepadKeyNames::MotionController_Left_Trigger("MotionController_Left_Trigger");

const FGamepadKeyNames::Type FGamepadKeyNames::MotionController_Left_Grip1("MotionController_Left_Grip1");
const FGamepadKeyNames::Type FGamepadKeyNames::MotionController_Left_Grip2("MotionController_Left_Grip2");

const FGamepadKeyNames::Type FGamepadKeyNames::MotionController_Left_Thumbstick("MotionController_Left_Thumbstick");
const FGamepadKeyNames::Type FGamepadKeyNames::MotionController_Left_Thumbstick_Up("MotionController_Left_Thumbstick_Up");
const FGamepadKeyNames::Type FGamepadKeyNames::MotionController_Left_Thumbstick_Down("MotionController_Left_Thumbstick_Down");
const FGamepadKeyNames::Type FGamepadKeyNames::MotionController_Left_Thumbstick_Left("MotionController_Left_Thumbstick_Left");
const FGamepadKeyNames::Type FGamepadKeyNames::MotionController_Left_Thumbstick_Right("MotionController_Left_Thumbstick_Right");

	//		Right Controller
const FGamepadKeyNames::Type FGamepadKeyNames::MotionController_Right_FaceButton1("MotionController_Right_FaceButton1");
const FGamepadKeyNames::Type FGamepadKeyNames::MotionController_Right_FaceButton2("MotionController_Right_FaceButton2");
const FGamepadKeyNames::Type FGamepadKeyNames::MotionController_Right_FaceButton3("MotionController_Right_FaceButton3");
const FGamepadKeyNames::Type FGamepadKeyNames::MotionController_Right_FaceButton4("MotionController_Right_FaceButton4");
const FGamepadKeyNames::Type FGamepadKeyNames::MotionController_Right_FaceButton5("MotionController_Right_FaceButton5");
const FGamepadKeyNames::Type FGamepadKeyNames::MotionController_Right_FaceButton6("MotionController_Right_FaceButton6");
const FGamepadKeyNames::Type FGamepadKeyNames::MotionController_Right_FaceButton7("MotionController_Right_FaceButton7");
const FGamepadKeyNames::Type FGamepadKeyNames::MotionController_Right_FaceButton8("MotionController_Right_FaceButton8");

const FGamepadKeyNames::Type FGamepadKeyNames::MotionController_Right_Shoulder("MotionController_Right_Shoulder");
const FGamepadKeyNames::Type FGamepadKeyNames::MotionController_Right_Trigger("MotionController_Right_Trigger");

const FGamepadKeyNames::Type FGamepadKeyNames::MotionController_Right_Grip1("MotionController_Right_Grip1");
const FGamepadKeyNames::Type FGamepadKeyNames::MotionController_Right_Grip2("MotionController_Right_Grip2");

const FGamepadKeyNames::Type FGamepadKeyNames::MotionController_Right_Thumbstick("MotionController_Right_Thumbstick");
const FGamepadKeyNames::Type FGamepadKeyNames::MotionController_Right_Thumbstick_Up("MotionController_Right_Thumbstick_Up");
const FGamepadKeyNames::Type FGamepadKeyNames::MotionController_Right_Thumbstick_Down("MotionController_Right_Thumbstick_Down");
const FGamepadKeyNames::Type FGamepadKeyNames::MotionController_Right_Thumbstick_Left("MotionController_Right_Thumbstick_Left");
const FGamepadKeyNames::Type FGamepadKeyNames::MotionController_Right_Thumbstick_Right("MotionController_Right_Thumbstick_Right");

	//   Motion Controller Axes
	//		Left Controller
const FGamepadKeyNames::Type FGamepadKeyNames::MotionController_Left_Thumbstick_X("MotionController_Left_Thumbstick_X");
const FGamepadKeyNames::Type FGamepadKeyNames::MotionController_Left_Thumbstick_Y("MotionController_Left_Thumbstick_Y");
const FGamepadKeyNames::Type FGamepadKeyNames::MotionController_Left_TriggerAxis("MotionController_Left_TriggerAxis");

	//		Right Controller
const FGamepadKeyNames::Type FGamepadKeyNames::MotionController_Right_Thumbstick_X("MotionController_Right_Thumbstick_X");
const FGamepadKeyNames::Type FGamepadKeyNames::MotionController_Right_Thumbstick_Y("MotionController_Right_Thumbstick_Y");
const FGamepadKeyNames::Type FGamepadKeyNames::MotionController_Right_TriggerAxis("MotionController_Right_TriggerAxis");

void FDisplayMetrics::PrintToLog() const
{
	UE_LOG(LogInit, Log, TEXT("Display metrics:"));
	UE_LOG(LogInit, Log, TEXT("  PrimaryDisplayWidth: %d"), PrimaryDisplayWidth);
	UE_LOG(LogInit, Log, TEXT("  PrimaryDisplayHeight: %d"), PrimaryDisplayHeight);
	UE_LOG(LogInit, Log, TEXT("  PrimaryDisplayWorkAreaRect:"));
	UE_LOG(LogInit, Log, TEXT("    Left=%d, Top=%d, Right=%d, Bottom=%d"), 
		PrimaryDisplayWorkAreaRect.Left, PrimaryDisplayWorkAreaRect.Top, 
		PrimaryDisplayWorkAreaRect.Right, PrimaryDisplayWorkAreaRect.Bottom);

	UE_LOG(LogInit, Log, TEXT("  VirtualDisplayRect:"));
	UE_LOG(LogInit, Log, TEXT("    Left=%d, Top=%d, Right=%d, Bottom=%d"), 
		VirtualDisplayRect.Left, VirtualDisplayRect.Top, 
		VirtualDisplayRect.Right, VirtualDisplayRect.Bottom);

	UE_LOG(LogInit, Log, TEXT("  TitleSafePaddingSize: %s"), *TitleSafePaddingSize.ToString());
	UE_LOG(LogInit, Log, TEXT("  ActionSafePaddingSize: %s"), *ActionSafePaddingSize.ToString());

	const int NumMonitors = MonitorInfo.Num();
	UE_LOG(LogInit, Log, TEXT("  Number of monitors: %d"), NumMonitors);

	for (int MonitorIdx = 0; MonitorIdx < NumMonitors; ++MonitorIdx)
	{
		const FMonitorInfo & Info = MonitorInfo[MonitorIdx];
		UE_LOG(LogInit, Log, TEXT("    Monitor %d"), MonitorIdx);
		UE_LOG(LogInit, Log, TEXT("      Name: %s"), *Info.Name);
		UE_LOG(LogInit, Log, TEXT("      ID: %s"), *Info.ID);
		UE_LOG(LogInit, Log, TEXT("      NativeWidth: %d"), Info.NativeWidth);
		UE_LOG(LogInit, Log, TEXT("      NativeHeight: %d"), Info.NativeHeight);
		UE_LOG(LogInit, Log, TEXT("      bIsPrimary: %s"), Info.bIsPrimary ? TEXT("true") : TEXT("false"));
	}
}
