#include "PluginUI/MainMenu/PluginFlowCoordinator.hpp"
#include "PluginUI/MainMenu/PluginViewController.hpp"
using namespace thinsaberui::UI;

DEFINE_TYPE(thinsaberui::UI, PluginFlowCoordinator);

#include "HMUI/ViewController_AnimationDirection.hpp"
#include "HMUI/ViewController_AnimationType.hpp"
using namespace HMUI;

#include "bsml/shared/Helpers/creation.hpp"

void PluginFlowCoordinator::DidActivate(bool firstActivation, bool addedToHierarchy, bool screenSystemEnabling) 
{
    if (!firstActivation) return;
    viewController = BSML::Helpers::CreateViewController<thinsaberui::UI::PluginViewController*>();

    showBackButton = true;
    ProvideInitialViewControllers(viewController, nullptr, nullptr, nullptr, nullptr);
    SetTitle("Thin Saber", ViewController::AnimationType::In);
}

void PluginFlowCoordinator::BackButtonWasPressed(ViewController *topViewController) 
{
    this->parentFlowCoordinator->DismissFlowCoordinator(this, ViewController::AnimationDirection::Horizontal, nullptr, false);
}