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

#include "ConfigFile.h"

void ConfigFile::load() {

    ifstream file(filePath, ios::in);
    if (!file.good()) {
        FileNotFoundException ex(filePath);
        throw ex;
    }
    std::string line;
    while (std::getline(file, line)) {
        std::size_t pos = line.find("=");
        if (pos != std::string::npos) {
            save(line.substr(0, pos), line.substr(pos + 1, line.size() - pos - 1));
        }
    }
    file.close();
    loaded = true;
}

void ConfigFile::commit() {
    ofstream file(filePath, ios::ate | ios::out);
    if (!file.good()) {
        FileNotFoundException ex(filePath);
        throw ex;
    }
    for (auto const &x : configMap) {
        file << x.first << "=" << x.second << std::endl;
    }
    file.close();
}