// Copyright (c) 2010 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "chrome/browser/chromeos/dom_ui/language_mozc_options_handler.h"

#include "app/l10n_util.h"
#include "base/string_number_conversions.h"
#include "base/utf_string_conversions.h"
#include "base/values.h"
#include "chrome/browser/chromeos/dom_ui/language_options_util.h"
#include "chrome/browser/chromeos/language_preferences.h"
#include "grit/generated_resources.h"

namespace chromeos {

LanguageMozcOptionsHandler::LanguageMozcOptionsHandler() {
}

LanguageMozcOptionsHandler::~LanguageMozcOptionsHandler() {
}

void LanguageMozcOptionsHandler::GetLocalizedValues(
    DictionaryValue* localized_strings) {
  DCHECK(localized_strings);
  // Language Mozc page - ChromeOS
  for (size_t i = 0; i < language_prefs::kNumMozcBooleanPrefs; ++i) {
    localized_strings->SetString(
        GetI18nContentValue(language_prefs::kMozcBooleanPrefs[i]),
        l10n_util::GetStringUTF16(
            language_prefs::kMozcBooleanPrefs[i].message_id));
  }

  for (size_t i = 0; i < language_prefs::kNumMozcMultipleChoicePrefs; ++i) {
    const language_prefs::LanguageMultipleChoicePreference<const char*>&
        preference = language_prefs::kMozcMultipleChoicePrefs[i];
    localized_strings->SetString(
        GetI18nContentValue(preference),
        l10n_util::GetStringUTF16(preference.label_message_id));
    localized_strings->Set(GetTemplateDataPropertyName(preference),
                           CreateMultipleChoiceList(preference));
  }

  for (size_t i = 0; i < language_prefs::kNumMozcIntegerPrefs; ++i) {
    const language_prefs::LanguageIntegerRangePreference& preference =
        language_prefs::kMozcIntegerPrefs[i];
    localized_strings->SetString(
        GetI18nContentValue(preference),
        l10n_util::GetStringUTF16(preference.message_id));
    localized_strings->SetString(
        GetTemplateDataMinName(preference),
        base::IntToString(preference.min_pref_value));
    localized_strings->SetString(
        GetTemplateDataMaxName(preference),
        base::IntToString(preference.max_pref_value));
  }
}

}  // namespace chromeos
