/* This file is part of KDevelop
 * Copyright 2011 Mathieu Lornac <mathieu.lornac@gmail.com>
 * Copyright 2011 Damien Coppel <damien.coppel@gmail.com>
 * Copyright 2011 Lionel Duc <lionel.data@gmail.com>

   This program is free software; you can redistribute it and/or
   modify it under the terms of the GNU General Public
   License as published by the Free Software Foundation; either
   version 2 of the License, or (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
    General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; see the file COPYING.  If not, write to
   the Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.
*/

#ifndef _CPPCHECK_SEVERITYMODEL_H_
#define _CPPCHECK_SEVERITYMODEL_H_

#include "imodel.h"
#include "cppcheckitems.h"
#include "cppcheck_severity_item.h"

#include <QStringList>
#include <QAbstractItemModel>

namespace cppcheck
{

class CppcheckError;
class CppcheckSererityItem;

/**
 * A class that represents the item model for cppcheck_severity
 */
class CppcheckSeverityModel : public QAbstractItemModel,
                    public cppcheck::Model,
                    public CppcheckItem

{
    Q_OBJECT

public:
    CppcheckSeverityModel(QObject* parent = 0);
    ~CppcheckSeverityModel();

    QAbstractItemModel  *getQAbstractItemModel(int);

    QVariant getColumnAtSnapshot(int snap, CppcheckSeverityItem::Columns col);
    QModelIndex index(int, int, const QModelIndex&) const;
    QModelIndex parent(const QModelIndex&) const;
    int rowCount(const QModelIndex &parent = QModelIndex()) const;
    int columnCount(const QModelIndex&) const;
    QVariant data(const QModelIndex &index, int role) const;
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const;
    // Item
    CppcheckItem* parent() const;

    void incomingData(QString, QString, int, QString, QString, QString, QString, QString);

public slots:
    /////SLOTS WRAPPER////
    /**
     * Reception of a new item in the model
     */
    virtual void newItem(cppcheck::ModelItem *item);
    /**
     * Resets the model content
     */
    void reset();
    ////END SLOTS WRAPER////
private:
    CppcheckSeverityItem *m_rootItem;
};

}
#endif /* _CPPCHECK_SEVERITYMODEL_H_ */