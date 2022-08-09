//Copyright 2017 Ryan Wick

//This file is part of Bandage

//Bandage is free software: you can redistribute it and/or modify
//it under the terms of the GNU General Public License as published by
//the Free Software Foundation, either version 3 of the License, or
//(at your option) any later version.

//Bandage is distributed in the hope that it will be useful,
//but WITHOUT ANY WARRANTY; without even the implied warranty of
//MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//GNU General Public License for more details.

//You should have received a copy of the GNU General Public License
//along with Bandage.  If not, see <http://www.gnu.org/licenses/>.

#pragma once

#include "graphsearch/graphsearch.h"

#include <QDir>
#include <QString>

// This is a class to hold all BLAST search related stuff.
// An instance of it is made available to the whole program
// as a global.
class BlastSearch : public search::GraphSearch {
public:
    explicit BlastSearch(const QDir &workDir = QDir::temp());
    virtual ~BlastSearch() = default;

    int loadBlastQueriesFromFastaFile(QString fullFileName);
    void blastQueryChanged(const QString& queryName);

    QString doAutoGraphSearch(const AssemblyGraph &graph, QString queriesFilename,
                              QString extraParameters = "") override;

    QString name() const override { return "BLAST"; }
private:
    bool findTools();

    QString m_makeblastdbCommand, m_blastnCommand, m_tblastnCommand;
};