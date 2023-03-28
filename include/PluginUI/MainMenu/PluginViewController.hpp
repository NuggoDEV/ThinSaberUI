#pragma once

#include "custom-types/shared/macros.hpp"
#include "HMUI/ViewController.hpp"
#include "bsml/shared/BSML.hpp"
#include "bsml/shared/BSML/Components/Settings/SliderSetting.hpp"

DECLARE_CLASS_CODEGEN(thinsaberui::UI, PluginViewController, HMUI::ViewController,
    DECLARE_OVERRIDE_METHOD(void, DidActivate, il2cpp_utils::FindMethodUnsafe("HMUI", "ViewController", "DidActivate", 3), bool firstActivation, bool addedToHierarchy, bool screenSystemEnabling);

    DECLARE_BSML_PROPERTY(bool, ModToggle);
    DECLARE_BSML_PROPERTY(float, SaberLengthVal);
    DECLARE_BSML_PROPERTY(float, SaberWidthVal);

    DECLARE_INSTANCE_FIELD(BSML::SliderSetting*, SaberLengthID);
    DECLARE_INSTANCE_FIELD(BSML::SliderSetting*, SaberWidthID);

    DECLARE_INSTANCE_METHOD(void, ResetLength);
    DECLARE_INSTANCE_METHOD(void, ResetWidth);
)