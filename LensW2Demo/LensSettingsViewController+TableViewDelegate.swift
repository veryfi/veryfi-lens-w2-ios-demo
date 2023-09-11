//
//  LensSettingsViewController+TableViewDelegate.swift
//  LensW2Demo
//
//  Created by Bernardo Restrepo on 12/03/22.
//

import UIKit

extension LensSettingsViewController: UITableViewDelegate {
    func tableView(_ tableView: UITableView, didSelectRowAt indexPath: IndexPath) {
        let type = sections[indexPath.section][indexPath.row].1
        if type == .stringValueCell || type == .doubleValueCell || type == .integerValueCell {
            handleValueCellTap(indexPath: indexPath)
        } else if type == .stringColorCell {
            handleColorCellTap(indexPath: indexPath)
        }
    }
}
