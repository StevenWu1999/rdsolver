using namespace std;

void open_files(ofstream &density_map, ofstream &pressure_map, ofstream &velocity_map, ofstream &du_file){
        density_map.open("density.txt");
        pressure_map.open("pressure.txt");
        velocity_map.open("velocity.txt");
        du_file.open("mass_flux.txt");
        return;
}

void close_files(ofstream &density_map, ofstream &pressure_map, ofstream &velocity_map, ofstream &du_file){
        density_map.close();
        pressure_map.close();
        velocity_map.close();
        du_file.close();
        return;
}

void output_state(ofstream &density_map, ofstream &pressure_map, ofstream &velocity_map, ofstream &du_file, vector<centre> points, double t, double dt, double dx){
        int i;
        double total_density;
        vector<centre>::iterator it_vert;

        for(it_vert=points.begin(),i=0;it_vert<points.end();it_vert++,i++){
                        density_map << points[i].get_x() << "\t" << points[i].get_mass_density() << endl;
                        pressure_map << points[i].get_x() << "\t" << points[i].get_pressure() << endl;
                        velocity_map << points[i].get_x() << "\t" << points[i].get_velocity() << endl;
                        total_density += points[i].get_mass_density()*dx;
        }
        cout << "*********************************************************" << endl;            // right out time and total density to terminal
        cout << "time\t" << t << " \t-> total mass =\t" << total_density  << "\ttime step = \t" << dt << endl;
        density_map << " " << endl;
        pressure_map << " " << endl;
        velocity_map << " " << endl;
        return;
}