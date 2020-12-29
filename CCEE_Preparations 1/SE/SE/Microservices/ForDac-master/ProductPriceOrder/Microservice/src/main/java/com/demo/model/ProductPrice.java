package com.demo.model;

import lombok.AllArgsConstructor;
import lombok.Data;
import lombok.NoArgsConstructor;

@Data @NoArgsConstructor @AllArgsConstructor
public class ProductPrice {

	public Double taxPercent = 8.75; 
	
//	@Id	@GeneratedValue(strategy=GenerationType.AUTO)
//	private Long id;
	
	private Double productMRP = 0.0; 
	private Integer discountPercent = 0; 
	private Boolean isDiscountApplicable;
	
	private Double taxAmount = 0.0;
	private Double discountAmount = 0.0;
	private Double priceAfterDiscount = 0.0;
	private Double payableAmount = 0.0;
}
