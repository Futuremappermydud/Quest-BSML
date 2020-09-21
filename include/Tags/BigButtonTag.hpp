﻿#include BeatSaberMarkupLanguage.Components;
#include HMUI;
#include System.Linq;
#include TMPro;
#include UnityEngine;
#include UnityEngine.UI;
#include "Components/Strokable.hpp"

namespace BeatSaberMarkupLanguage::Tags {
    class BigButtonTag : BSMLTag {
      public:
        std::string Aliases[] = { "big-button" };

        public override GameObject CreateObject(Transform parent)
        {
            Button button = MonoBehaviour.Instantiate(Resources.FindObjectsOfTypeAll<Button>().Last(x => (x.name == "SoloFreePlayButton")), parent, false);
            button.name = "BSMLBigButton";
            button.interactable = true;

            Object.Destroy(button.GetComponent<HoverHint>());
            Object.Destroy(button.GetComponent<LocalizedHoverHint>());
            Polyglot.LocalizedTextMeshProUGUI localizer = button.GetComponentInChildren<Polyglot.LocalizedTextMeshProUGUI>();
            if (localizer != null)
                Object.Destroy(localizer);
            button.gameObject.AddComponent<ExternalComponents>().components.Add(button.GetComponentInChildren<TextMeshProUGUI>());

            Image strokeImage = button.gameObject.GetComponentsInChildren<Image>(true).Where(x => x.gameObject.name == "Stroke").FirstOrDefault();
            if (strokeImage != null)
            {
                Strokable strokable = button.gameObject.AddComponent<Strokable>();
                strokable.image = strokeImage;
                strokable.SetType(StrokeType.Regular);
            }

            Image iconImage = button.gameObject.GetComponentsInChildren<Image>(true).Where(x => x.gameObject.name == "Icon").FirstOrDefault();
            if (iconImage != null)
            {
                ButtonIconImage btnIcon = button.gameObject.AddComponent<ButtonIconImage>();
                btnIcon.image = iconImage;
            }

            Image artworkImage = button.gameObject.GetComponentsInChildren<Image>(true).Where(x => x.gameObject.name == "BGArtwork").FirstOrDefault();
            if (artworkImage != null)
            {
                ButtonArtworkImage btnArt = button.gameObject.AddComponent<ButtonArtworkImage>();
                btnArt.image = artworkImage;
            }

            return button.gameObject;
        }
    }
}