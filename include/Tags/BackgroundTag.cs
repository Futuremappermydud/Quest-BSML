﻿using BeatSaberMarkupLanguage.Components;
using UnityEngine;
using UnityEngine.UI;

namespace BeatSaberMarkupLanguage.Tags
{
    public class BackgroundTag : BSMLTag
    {
        public override string[] Aliases => new[] { "bg", "background", "div" };

        public override GameObject CreateObject(Transform parent)
        {
            GameObject gameObject = new GameObject();
            gameObject.name = "BSMLBackground";
            gameObject.transform.SetParent(parent, false);
            gameObject.AddComponent<ContentSizeFitter>();
            gameObject.AddComponent<Backgroundable>();

            RectTransform rectTransform = gameObject.transform as RectTransform;
            rectTransform.anchorMin = new Vector2(0, 0);
            rectTransform.anchorMax = new Vector2(1, 1);
            rectTransform.sizeDelta = new Vector2(0, 0);

            return gameObject;
        }
    }
}
