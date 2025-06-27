from uiCuClasa import ui

from controller.serviceStudenti import ServiceStudenti
from controller.serviceDiscipline import ServiceDiscipline
from controller.serviceNote import ServiceNote

from repository.repoStudenti import RepoStudenti
from repository.repoDiscipline import RepoDiscipline
from repository.repoNote import RepoNote

from repository.file_repoStudenti import FileRepoStudenti
from repository.file_repoDiscipline import FileRepoDiscipline
from repository.file_repoNote import FileRepoNote

from tests.repositoryTests.repo_test import run_tests_repository
from tests.repositoryTests.file_repo_test import run_tests_file_repository
from tests.serviceTests.service_test import run_tests_service
from application_coordinator import repositoryCuFisiere

run_tests_file_repository()
run_tests_repository()
run_tests_service()

if not repositoryCuFisiere:
    repoStudenti = RepoStudenti()
    repoDiscipline = RepoDiscipline()
    repoNote = RepoNote()
else:
    repoStudenti = FileRepoStudenti("C:/Users/Catalin/Documents/FundamenteleProgramarii/Laburi/Lab_7-9+10/student.txt")
    repoDiscipline = FileRepoDiscipline("disciplina.txt")
    repoNote = FileRepoNote("grades.txt")

serviceStudenti = ServiceStudenti(repoStudenti)
serviceDiscipline = ServiceDiscipline(repoDiscipline)
serviceNote = ServiceNote(repoNote, repoStudenti, repoDiscipline)

consola = ui(serviceStudenti, serviceDiscipline, serviceNote)
consola.run()
