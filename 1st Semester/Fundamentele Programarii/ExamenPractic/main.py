from repository.repo_spectacole import RepositorySpectacole
from business.service_spectacole import ServiceSpectacole
from validator.validator_spectacole import ValidatorSpectacol
from ui.ui import UI
import unittest

repo = RepositorySpectacole("C:/User/Catalin/Documents/FundamenteleProgramarii/Practic/spectacole.txt")

validator = ValidatorSpectacol()
service = ServiceSpectacole(repo, validator)

ui = UI(service)

def run_tests():
    unittest.main(module="tests.test_domain", exit = False)
    unittest.main(module="tests.test_validator", exit = False)
    unittest.main(module="tests.test_repo", exit=False)
    unittest.main(module="tests.test_service", exit=False)

run_tests()

ui.run()