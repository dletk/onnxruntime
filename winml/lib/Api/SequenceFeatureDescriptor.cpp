﻿// Copyright (c) Microsoft Corporation.
// Licensed under the MIT License.

#include "pch.h"

#include "SequenceFeatureDescriptor.h"

using namespace Windows::AI::MachineLearning;

namespace winrt::Windows::AI::MachineLearning::implementation {
SequenceFeatureDescriptor::SequenceFeatureDescriptor(
    const char* name,
    const char* description,
    bool is_required,
    winml::ILearningModelFeatureDescriptor descriptor) : name_(WinML::Strings::HStringFromUTF8(name)),
                                                         description_(WinML::Strings::HStringFromUTF8(description)),
                                                         is_required_(is_required),
                                                         element_descriptor_(descriptor) {}
SequenceFeatureDescriptor::SequenceFeatureDescriptor(
    hstring const& Name,
    hstring const& Description,
    bool IsRequired,
    Windows::AI::MachineLearning::ILearningModelFeatureDescriptor const& ElementDescriptor) : 
        name_(Name),
        description_(Description),
        is_required_(IsRequired),
        element_descriptor_(ElementDescriptor) {
}


winml::ILearningModelFeatureDescriptor
SequenceFeatureDescriptor::ElementDescriptor() try {
  return element_descriptor_;
}
WINML_CATCH_ALL

hstring
SequenceFeatureDescriptor::Name() try {
  return name_;
}
WINML_CATCH_ALL

hstring
SequenceFeatureDescriptor::Description() try {
  return description_;
}
WINML_CATCH_ALL

winml::LearningModelFeatureKind
SequenceFeatureDescriptor::Kind() try {
  return LearningModelFeatureKind::Sequence;
}
WINML_CATCH_ALL

bool SequenceFeatureDescriptor::IsRequired() try {
  return is_required_;
}
WINML_CATCH_ALL

HRESULT
SequenceFeatureDescriptor::GetName(
    const wchar_t** name,
    uint32_t* cchName) {
  *name = name_.data();
  *cchName = static_cast<uint32_t>(name_.size());
  return S_OK;
}

HRESULT
SequenceFeatureDescriptor::GetDescription(
    const wchar_t** description,
    uint32_t* cchDescription) {
  *description = description_.data();
  *cchDescription = static_cast<uint32_t>(description_.size());
  return S_OK;
}
}  // namespace winrt::Windows::AI::MachineLearning::implementation