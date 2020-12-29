package com.demo.entity;

import javax.persistence.Entity;
import javax.persistence.GeneratedValue;
import javax.persistence.GenerationType;
import javax.persistence.Id;
import javax.persistence.Table;

import lombok.AllArgsConstructor;
import lombok.Data;
import lombok.NoArgsConstructor;

@Entity
@Table(name = "product_price", schema = "schema_shopping")
@Data @NoArgsConstructor @AllArgsConstructor

public class Price {
	@Id
	@GeneratedValue(strategy = GenerationType.AUTO)
	private Long id;
	private Float discount_amount;
	private Float discount_percent;
	private Boolean is_discount_applicable;
	private Float payable_amount;
	private Float price_after_discount;
	private Float product_id;
	private Float productmrp;
	private Float tax_amount;
	private Float tax_percent;
}
