// Copyright (c) Microsoft Corporation.
// Licensed under the MIT License.
#pragma once
#include "ExecutionContext.h"

namespace AppInstaller::CLI::Workflow
{
    // Handles all opened source(s) agreements if needed.
    // Required Args: The source to be checked for agreements
    // Inputs: None
    // Outputs: None
    struct HandleSourceAgreements : public WorkflowTask
    {
        HandleSourceAgreements(Repository::Source source) : WorkflowTask("HandleSourceAgreements"), m_source(std::move(source)) {}

        void operator()(Execution::Context& context) const override;

    private:
        Repository::Source m_source;
    };

    // Shows all the prompts required for a single package, e.g. for package agreements
    // Required Args: None
    // Inputs: Manifest, Installer
    // Outputs: None
    struct ShowPromptsForSinglePackage : public WorkflowTask
    {
        ShowPromptsForSinglePackage(bool ensureAgreementsAcceptance) :
            WorkflowTask("ShowPromptsForSinglePackage"), m_ensureAgreementsAcceptance(ensureAgreementsAcceptance) {}

        void operator()(Execution::Context& context) const override;

    private:
        bool m_ensureAgreementsAcceptance;
    };

    // Shows all the prompts required for multiple package, e.g. for package agreements
    // Required Args: None
    // Inputs: PackageSubContexts
    // Outputs: None
    struct ShowPromptsForMultiplePackages : public WorkflowTask
    {
        ShowPromptsForMultiplePackages(bool ensureAgreementsAcceptance) :
            WorkflowTask("ShowPromptsForMultiplePackages"), m_ensureAgreementsAcceptance(ensureAgreementsAcceptance) {}

        void operator()(Execution::Context& context) const override;

    private:
        bool m_ensureAgreementsAcceptance;
    };
}