#include "main.hpp"
#include "thinsabercore/shared/API/SaberScaler.hpp"
#include "CustomTypes/Vector3.hpp"

#include "PluginUI/MainMenu/PluginViewController.hpp"
using namespace thinsaberui::UI;
DEFINE_TYPE(thinsaberui::UI, PluginViewController);

#include "assets.hpp"
#include "bsml/shared/BSML.hpp"

namespace thinsaberui::UI
{
    void PluginViewController::DidActivate(bool firstActivation, bool addedToHierarchy, bool screenSystemEnabling)
    {
        if (!firstActivation) return;
        BSML::parse_and_construct(IncludedAssets::settings_bsml, this->get_transform(), this);
    }

    void PluginViewController::ResetLength() 
    {
        ThinSaberCore::SaberScaler::setSaberLength(1.0f);
        SaberLengthID->set_Value(1.0f);
    }

    void PluginViewController::ResetWidth() 
    {
        ThinSaberCore::SaberScaler::setSaberThickness(1.0f);
        SaberWidthID->set_Value(1.0f);
    }

    bool PluginViewController::get_ModToggle() { return ThinSaberCore::SaberScaler::getCoreScalerDisabled(); }
    void PluginViewController::set_ModToggle(bool value) { ThinSaberCore::SaberScaler::setCoreScalerDisabled(!value); }

    float PluginViewController::get_SaberLengthVal() { return ThinSaberCore::SaberScaler::getSaberLength(); }
    void PluginViewController::set_SaberLengthVal(float value) { ThinSaberCore::SaberScaler::setSaberLength(value); }

    float PluginViewController::get_SaberWidthVal() { return ThinSaberCore::SaberScaler::getSaberThickness(); }
    void PluginViewController::set_SaberWidthVal(float value) { ThinSaberCore::SaberScaler::setSaberThickness(value); }
}