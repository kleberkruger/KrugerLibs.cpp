/*
 * Created by Kleber Kruger on 21/07/16.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#include <iostream>
#include <zconf.h>
#include "ConfigFile/ConfigFile.h"

using namespace std;

int main() {

    chdir("/Users/kleberkruger/Documents/CLionProjects/KrugerLibs/ConfigFile");

    try {
        ConfigFile configFile("Settings.txt");
        configFile.load();
//        short a = 50;
//        configFile.save("pro 2", a);

//        configFile.commit();

        cout << configFile.getUShort("prop_3") << endl;

    } catch (FileNotFoundException &ex) {
        std::cout << ex.what() << std::endl;
    } catch (InvalidPropertyName &ex) {
        std::cout << ex.what() << std::endl;
    }

    return EXIT_SUCCESS;
}