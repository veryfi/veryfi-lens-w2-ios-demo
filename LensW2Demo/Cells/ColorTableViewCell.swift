//
//  ColorTableViewCell.swift
//  LensW2Demo
//
//  Created by Bernardo Restrepo on 12/03/22.
//

import UIKit

class ColorTableViewCell: UITableViewCell {

    @IBOutlet weak var titleLabel: UILabel!
    @IBOutlet weak var settingView: UIView!
    
    override func awakeFromNib() {
        super.awakeFromNib()
        // Initialization code
        settingView.layer.cornerRadius = 10
    }

    override func setSelected(_ selected: Bool, animated: Bool) {
        super.setSelected(selected, animated: animated)

        // Configure the view for the selected state
    }

}
