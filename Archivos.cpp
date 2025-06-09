#include"Archivos.h"

void GestionArchivos::GuardarCriaturas(ColeccionT<Criatura>* lista, string& nomArch) {
	ofstream arch(nomArch.c_str());
	if (arch.is_open()) {
		Criatura** cri = lista->getVec();
		for (int i = 0; i < lista->getTamanio(); i++) {
			cri[i]->Guardar(arch);
		}
		arch.close();
	}
}
void GestionArchivos::LecturaCriaturas(ColeccionT<Criatura>* lista, string& nomArch,Ecosistema* eco){
	ifstream arch(nomArch);
	if (arch.is_open()) {
		string tipo;
		while (!arch.eof()) {
			arch >> tipo;
			if (tipo == "Carnivoro") {
				Criatura* cri = Carnivoro::Lectura(arch,eco);
				if (arch.good()) {
					lista->agregar(cri);
				}
				if (tipo == "Herbivoro") {
					Criatura* cri = Herbivoro::Lectura(arch, eco);
					if (arch.good()) {
						lista->agregar(cri);
					}
				}
				if (tipo == "Omnivoro") {
					Criatura* cri = Omnivoro::Lectura(arch, eco);
					if (arch.good()) {
						lista->agregar(cri);
					}
				}
			}
		}
		arch.close();
	}
}

void GestionArchivos::GuardarRecursos(ColeccionT<Recurso>* lista, string& nomArch) {
	ofstream arch(nomArch.c_str());
	if (arch.is_open()) {
		Recurso** rec = lista->getVec();
		for (int i = 0; i < lista->getTamanio(); i++) {
			rec[i]->Guardar(arch);
		}
		arch.close();
	}
}
void GestionArchivos::LecturaRecursos(ColeccionT<Recurso>* lista, string& nomArch, Ecosistema* eco) {
	ifstream arch(nomArch);
	if (arch.is_open()) {
		string tipo;
		while (!arch.eof()) {
			arch >> tipo;
			if (tipo == "Agua") {
				Recurso* cri = Agua::Lectura(arch, eco);
				if (arch.good()) {
					lista->agregar(cri);
				}
				if (tipo == "Carne") {
					Recurso* cri = Carne::Lectura(arch, eco);
					if (arch.good()) {
						lista->agregar(cri);
					}
				}
				if (tipo == "Planta") {
					Recurso* cri = Planta::Lectura(arch, eco);
					if (arch.good()) {
						lista->agregar(cri);
					}
				}
			}
		}
		arch.close();
	}
}
