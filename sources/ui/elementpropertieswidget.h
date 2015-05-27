/*
	Copyright 2006-2015 The QElectroTech Team
	This file is part of QElectroTech.

	QElectroTech is free software: you can redistribute it and/or modify
	it under the terms of the GNU General Public License as published by
	the Free Software Foundation, either version 2 of the License, or
	(at your option) any later version.

	QElectroTech is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
	GNU General Public License for more details.

	You should have received a copy of the GNU General Public License
	along with QElectroTech.  If not, see <http://www.gnu.org/licenses/>.
*/
#ifndef ELEMENTPROPERTIESWIDGET_H
#define ELEMENTPROPERTIESWIDGET_H

#include "abstractelementpropertieseditorwidget.h"

class Element;
class Diagram;
class QTabWidget;
class ElementsLocation;


class ElementPropertiesWidget : public AbstractElementPropertiesEditorWidget
{
		Q_OBJECT

	public:
		explicit ElementPropertiesWidget(Element *elmt, QWidget *parent = 0);
		void setElement(Element *element);
		void apply();
		void reset();
		bool setLiveEdit(bool live_edit);

	public slots:
		void findInPanel ();
		void editElement ();

	private:
		void buildGui();
		void updateUi();
		void addGeneralWidget();
		QWidget *generalWidget();

	signals:
			/// Signal emitted when users wish to locate an element from the diagram within elements collection
		void findElementRequired(const ElementsLocation &);
			/// Signal emitted when users wish to edit an element from the diagram
		void editElementRequired(const ElementsLocation &);

	private:
		Diagram *m_diagram;
		QTabWidget *m_tab;
		QList <AbstractElementPropertiesEditorWidget *> m_list_editor;
		QWidget *m_general_widget;
};

#endif // ELEMENTPROPERTIESWIDGET_H
