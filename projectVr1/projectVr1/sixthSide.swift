//
//  sixthSide.swift
//  projectVr1
//
//  Created by Rie Ruash on 19/02/2021.
//

import SwiftUI

struct sixthSide: View {
    @State private var squars6 = ["w","w","w","w","w","w","w","w","w"]
    var body: some View {
        
            VStack {
                ZStack{
                    Image("background2")
                        .resizable()
                        .edgesIgnoringSafeArea(.all)
                    VStack{
                        
                        Spacer()
                        Text("Please choose the \ncolors for the sixth side:")
                            .font(.title)
                            .foregroundColor(Color.white)
                            
                            .bold()
                            .multilineTextAlignment(.center)
                        Spacer()
                        
                        Spacer()
                        //Spacer()
                        //Spacer()
                        
                        GridStack2(rows: 3, columns: 3) { row, col in
                            //private
                            //private var button_color = squars1[row + col]
                            Button(action: {
                                //Same code using switch
                                switch self.squars6[row*3 + col] {
                                case "y":
                                    self.squars6[row*3 + col] = "b"
                                case "b":
                                    self.squars6[row*3 + col] = "g"
                                case "g":
                                    self.squars6[row*3 + col] = "o"
                                case "o":
                                    self.squars6[row*3 + col] = "w"
                                case "w":
                                    self.squars6[row*3 + col] = "r"
                                default:
                                    self.squars6[row*3 + col] = "y"
                                }
                                
                                //print(self.squars6[row*3 + col])
                            }){
                                Spacer()
                                
                                switch self.squars6[row*3 + col] {
                                case "y":
                                    Color.yellow
                                        .border(/*@START_MENU_TOKEN@*/Color.black/*@END_MENU_TOKEN@*/, width: 3)
                                        .padding(5.0)
                                case "b":
                                    Color.blue
                                        .border(/*@START_MENU_TOKEN@*/Color.black/*@END_MENU_TOKEN@*/, width: 3)
                                        .padding(5.0)
                                case "g":
                                    Color.green
                                        .border(/*@START_MENU_TOKEN@*/Color.black/*@END_MENU_TOKEN@*/, width: 3)
                                        .padding(5.0)
                                case "o":
                                    Color.orange
                                        .border(/*@START_MENU_TOKEN@*/Color.black/*@END_MENU_TOKEN@*/, width: 3)
                                        .padding(5.0)
                                case "w":
                                    Color.white
                                        .border(/*@START_MENU_TOKEN@*/Color.black/*@END_MENU_TOKEN@*/, width: 3)
                                        .padding(5.0)
                                default:
                                    Color.red
                                        .border(/*@START_MENU_TOKEN@*/Color.black/*@END_MENU_TOKEN@*/, width: 3)
                                        .padding(5.0)
                                }
                                
                                Spacer()
                            }
                                }
                        Spacer()
                        
                        Spacer()
                        
                        /*NavigationLink(destination: next_page_col()){
                                Text("Click to Continue")
                                    .fontWeight(.bold)
                                    .font(.title)
                                    .padding()
                                    .background(Color.white)
                                    .foregroundColor(.black)
                                    .padding(10)
                                    .border(Color.white, width: 2)
                        }*/
                    }
                }
            }  .navigationBarTitle(Text("Sixth Side"))
        }
}

struct sixthSide_Previews: PreviewProvider {
    static var previews: some View {
        sixthSide()
    }
}
