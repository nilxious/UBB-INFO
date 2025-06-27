from repo.repo_statistici import RepoStatistici
from business.service_statistici import ServiceStatistici
from validators.validator_statistica import ValidatorStatistica
from ui import Ui

repoStatistici = RepoStatistici("C:/Users/Catalin/Documents/FundamenteleProgramarii/simulareFp/statistici.txt")
validatorStatistica = ValidatorStatistica()
serviceStatistici = ServiceStatistici(repoStatistici, validatorStatistica)
ui = Ui(serviceStatistici)

ui.run()
