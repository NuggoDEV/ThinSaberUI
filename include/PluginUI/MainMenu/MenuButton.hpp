#pragma once

#include "bsml/shared/Helpers/getters.hpp"
#include "bsml/shared/Helpers/creation.hpp"
#include "bsml/shared/BSML.hpp"

#include "HMUI/FlowCoordinator.hpp"
#include "HMUI/ViewController_AnimationDirection.hpp"
#include "HMUI/ViewController_AnimationType.hpp"
#include "PluginUI/MainMenu/PluginFlowCoordinator.hpp"

namespace thinsaberui::UI
{
    class MenuButton
    {
        HMUI::FlowCoordinator *parentFlow;
        PluginFlowCoordinator *flow;

        public:
            void Init()
            {
                BSML::Register::RegisterMenuButton("ThinSaber", "A frontend for the mod, ThinSaberCore", [this]()
                {
                    ShowFlow(false);
                });
            }

            void ShowFlow(bool immediately)
            {
                if (flow == nullptr || flow->m_CachedPtr.m_value == nullptr)
                    flow = BSML::Helpers::CreateFlowCoordinator<thinsaberui::UI::PluginFlowCoordinator *>();
                
                parentFlow = BSML::Helpers::GetMainFlowCoordinator()->YoungestChildFlowCoordinatorOrSelf();
                parentFlow->PresentFlowCoordinator(flow, nullptr, HMUI::ViewController::AnimationDirection::Horizontal, HMUI::ViewController::AnimationType::Out, false);
            }
    };

    inline static MenuButton menuButton;
}